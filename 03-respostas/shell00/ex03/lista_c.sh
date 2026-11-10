#!/bin/sh
ls -1 | grep '\.c$' | sed 's/\.c$//'
