Summary:        Community HW adaptation setup, %{flavour} flavour
License:        BSD-3-Clause
Name:           community-adaptation-%{flavour}
Version:        0.0.1
Release:        1
Provides:       community-adaptation
Group:          System
Requires:	ssu

%description
%{summary}.

%install

%if "%{flavour}" != "devel"
touch $RPM_BUILD_ROOT/init_disable_telnet
%endif

mkdir -p $RPM_BUILD_ROOT/%{_datadir}/community-adaptation/

sed -e "s|@FLAVOUR@|%{flavour}|g" \
    adaptation-community.ini.in > $RPM_BUILD_ROOT/%{_datadir}/community-adaptation/adaptation-community.ini.in

mkdir -p $RPM_BUILD_ROOT/%{_datadir}/ssu/features.d/

sed -e "s|@FLAVOUR@|%{flavour}|g" \
    adaptation-community-common.ini > $RPM_BUILD_ROOT/%{_datadir}/ssu/features.d/adaptation-community-common.ini

%files
%defattr(-,root,root,-)
/*

