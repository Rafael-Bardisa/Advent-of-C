add_executable(AoCexercise2)

target_sources(AoCexercise2
    PRIVATE exercise2.c
)

target_compile_features(AoCexercise2
    PRIVATE cxx_std_98
)