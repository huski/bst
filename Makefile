export EXECPATH=$(shell pwd)

default:
	cd src && $(MAKE) $@

clean:
	cd src && $(MAKE) $@
