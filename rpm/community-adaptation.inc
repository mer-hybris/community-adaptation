Summary:        Community HW adaptation setup, %{flavour} flavour
License:        BSD-3-Clause
Name:           community-adaptation-%{flavour}
Version:        0.0.3
Release:        1
Provides:       community-adaptation
Source0:        %{name}-%{version}.tar.bz2
Requires:       ssu
BuildArch:      noarch

%description
%{summary}.

%prep
%autosetup -n %{name}-%{version}

%install

%if "%{flavour}" == "testing" || "%{flavour}" == "localbuild-ota"
touch $RPM_BUILD_ROOT/init_disable_telnet
%endif

%if "%{flavour}" != "localbuild-ota"
mkdir -p $RPM_BUILD_ROOT/%{_datadir}/community-adaptation/

%if "%{flavour}" != "localbuild"
sed -e "s|@FLAVOUR@|%{flavour}|g" \
%if "%{flavour}" != "testing"
    -e "s|sailfishos_%%(releaseMajorMinor)|sailfish_latest_%%(arch)|g" \
%endif
    adaptation-community.ini.in > $RPM_BUILD_ROOT/%{_datadir}/community-adaptation/adaptation-community.ini.in
%else
    touch $RPM_BUILD_ROOT/%{_datadir}/community-adaptation/adaptation-community.ini.in
%endif

mkdir -p $RPM_BUILD_ROOT/%{_datadir}/ssu/features.d/

%if "%{flavour}" == "testing"
sed -e "s|@FLAVOUR@|testing|g" \
%else
sed -e "s|@FLAVOUR@|devel|g" \
    -e "s|sailfishos_%%(releaseMajorMinor)_%%(arch)|sailfish_latest_%%(arch)|g" \
%endif
    adaptation-community-common.ini > $RPM_BUILD_ROOT/%{_datadir}/ssu/features.d/adaptation-community-common.ini
%endif

%files
%if "%{flavour}" != "localbuild-ota"
%{_datadir}/community-adaptation
%{_datadir}/ssu/features.d/*
%endif
%if "%{flavour}" == "testing" || "%{flavour}" == "localbuild-ota"
/init_disable_telnet
%endif
