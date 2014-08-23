Name:       topcoder
Summary:    Topcoder study
Version:    0.1
Release:    1
Group:      Application
License:    GPLv2

%description
Topcoder study

%install
rm -rf %{buildroot}
mkdir -p %{buildroot}/usr/bin
mv ~/rpmbuild/BUILDROOT/kiwi-juice %{buildroot}/usr/bin
mv ~/rpmbuild/BUILDROOT/interesting-party %{buildroot}/usr/bin

%files
%attr(660,root,root) /usr/bin/kiwi-juice
%attr(660,root,root) /usr/bin/interesting-party
