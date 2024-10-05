.PHONY: init
init: pull_dependencies lsp_helper

.PHONY: clean
clean:
	rm -rf build
	mkdir build

.PHONY: test
test: clean
	cmake -GNinja -DCMAKE_BUILD_TYPE=Debug -DTARGET_GROUP=test -Bbuild -S.
	ninja -v -Cbuild
	ctest --verbose --test-dir build

.PHONY:  examples
examples: clean
	cmake -DCMAKE_BUILD_TYPE=Debug -DTARGET_GROUP=example -Bbuild -S.

.PHONY: lsp_helper
lsp_helper:
	bear -- make

.PHONY: gen_defs
gen_defs: pull_dependencies
	$(MAKE) -C vendor/vlcb-defs/codegen generate_c
	cp vendor/vlcb-defs/codegen/lang/c/output/vlcb_defs.h vlcb/include/defs/vlcb_defs.h

.PHONY: pull_dependencies
pull_dependencies:
	git submodule update --rebase --remote
