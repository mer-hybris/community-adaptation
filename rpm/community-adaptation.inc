Summary:        Community HW adaptation setup, %{flavour} flavour
License:        BSD-3-Clause
Name:           community-adaptation-%{flavour}
Version:        0.0.1
Release:        1
Provides:       community-adaptation
Group:          System
Source0:        %{name}-%{version}.tar.bz2
Requires:	ssu

%description
%{summary}.

%prep
%setup -q -n %{name}-%{version}

%install

%if "%{flavour}" != "devel"
touch $RPM_BUILD_ROOT/init_disable_telnet
%endif

mkdir -p $RPM_BUILD_ROOT/%{_datadir}/community-adaptation/

sed -e "s|@FLAVOUR@|%{flavour}|g" \
%if "%{flavour}" == "devel"
    -e "s|sailfishos_%%(release)|sailfish_latest_%%(arch)|g" \
%endif
    adaptation-community.ini.in > $RPM_BUILD_ROOT/%{_datadir}/community-adaptation/adaptation-community.ini.in

mkdir -p $RPM_BUILD_ROOT/%{_datadir}/ssu/features.d/

sed -e "s|@FLAVOUR@|%{flavour}|g" \
%if "%{flavour}" == "devel"
    -e "s|sailfishos_%%(release)|sailfish_latest_%%(arch)|g" \
%endif
    adaptation-community-common.ini > $RPM_BUILD_ROOT/%{_datadir}/ssu/features.d/adaptation-community-common.ini

%files
%defattr(-,root,root,-)
/*

