from conan import ConanFile, tools
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps
from conan.tools.files import copy

class ConanProject(ConanFile):

    name = "terminus_math"
    version = "0.0.1"

    license = "Terminus Proprietary"
    author  = "Marvin Smith"
    url     = "https://bitbucket.org/msmith81886/terminus-outcome/src"
    description = "Straightforward Math APIs"
    topics = ()

    settings = "os", "compiler", "build_type", "arch"

    options = {
        "with_tests": [True, False],
        "with_docs": [True, False],
        "with_coverage": [True, False]
    }

    default_options = {
        "with_tests": True,
        "with_docs": True,
        "with_coverage": False
    }


    def build_requirements(self):
        self.build_requires("terminus_cmake/1.0.0")
        self.build_requires( "gtest/1.13.0" )

    def requirements(self):
        self.requires("boost/1.82.0")

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables["CONAN_PKG_NAME"]        = self.name
        tc.variables["CONAN_PKG_VERSION"]     = self.version
        tc.variables["CONAN_PKG_DESCRIPTION"] = self.description
        tc.variables["CONAN_PKG_URL"]         = self.url

        tc.variables["TERMINUS_MATH_ENABLE_TESTS"]    = self.options.with_tests
        tc.variables["TERMINUS_MATH_ENABLE_DOCS"]     = self.options.with_docs
        tc.variables["TERMINUS_MATH_ENABLE_COVERAGE"] = self.options.with_coverage
        tc.generate()

        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = tools.files.collect_libs(self)

    def package_id(self):
        self.info.clear()

    def export_sources(self):

        for p in [ "CMakeLists.txt", "include/*", "test/*", "README.md" ]:
            copy( self, p, self.recipe_folder, self.export_sources_folder )