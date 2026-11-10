#!/bin/sh
grep ':/bin/bash$' | cut -d ':' -f 1 | sort
