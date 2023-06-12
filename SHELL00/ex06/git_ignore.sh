#!/bin/sh
git status -s --ignored | grep '^!!' | cut -d " " -f 2
