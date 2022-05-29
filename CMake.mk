all : build test

build:
	mkdir cmake-build-debug || true
	cd cmake-build-debug && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_DEPENDS_USE_COMPILER=FALSE -G "CodeBlocks - Unix Makefiles" ..
	cd cmake-build-debug && make all
.PHONY: build

clean:
	rm -rf ./cmake-build*

test: test-unit test-text
	@echo "All tests passing"
.PHONY: test

test-unit: build
	./cmake-build-debug/unit-tests
.PHONY: test-unit

test-text: build
	./cmake-build-debug/text-tests > text-tests.txt
	diff text-tests.txt text-tests.expected.txt
.PHONY: test-text

install: install-githooks

install-githooks:
	cp -R ./githooks/* .git/hooks/
	chmod +x .git/hooks/
.PHONY: install-githooks

pre-commit: build test
.PHONY: pre-commit

pre-push:
	@echo "Nothing to do"
.PHONY: pre-push

