all : build test

build:
	mkdir cmake-build-debug || true
	cd cmake-build-debug && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_DEPENDS_USE_COMPILER=FALSE -G "CodeBlocks - Unix Makefiles" ..
	cd cmake-build-debug && make all
.PHONY: build

clean:
	rm -rf ./cmake-build*

test:
	./cmake-build-debug/unit-tests
	./cmake-build-debug/text-tests
	@echo "All tests passing"
.PHONY: test