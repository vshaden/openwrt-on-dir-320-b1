#!/bin/sh
# Usage: event.sh <event> <if-name>

case "$1" in
if-create)
	;;
if-up)
	;;
if-down)
	;;
if-release)	
	;;
*)
	echo "Usage: $0 { if-create | if-up | if-down | if-release }" >&2
	exit 3
	;;
esac

