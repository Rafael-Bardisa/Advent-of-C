add_executable(AoCexercise1)

target_sources(AoCexercise1
    PRIVATE exercise1.c
)

target_compile_features(AoCexercise1
    PRIVATE cxx_std_98
)