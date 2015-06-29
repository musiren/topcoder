Name:       topcoder
Summary:    Topcoder study
Version:    0.1
Release:    2
Group:      Application
License:    GPLv2

%description
Topcoder study

%install
rm -rf %{buildroot}
mkdir -p %{buildroot}/usr/bin
mv ~/rpmbuild/BUILDROOT/kiwi-juice %{buildroot}/usr/bin
mv ~/rpmbuild/BUILDROOT/interesting-party %{buildroot}/usr/bin
mv ~/rpmbuild/BUILDROOT/encrypt %{buildroot}/usr/bin
mv ~/rpmbuild/BUILDROOT/interesting-digits %{buildroot}/usr/bin
mv ~/rpmbuild/BUILDROOT/send-package %{buildroot}/usr/bin

%files
%attr(0555,root,root) /usr/bin/kiwi-juice
%attr(0555,root,root) /usr/bin/interesting-party
%attr(0555,root,root) /usr/bin/encrypt
%attr(0555,root,root) /usr/bin/interesting-digits
%attr(0555,root,root) /usr/bin/send-package
