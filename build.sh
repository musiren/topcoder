#!/bin/sh

rm -rf ~/rpmbuild/*
make install prefix=~/rpmbuild/BUILDROOT
rpmbuild -bb packaging/topcoder.spec
