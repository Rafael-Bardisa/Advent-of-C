add_executable(AoCexercise4)

target_sources(AoCexercise4
    PRIVATE exercise4.c
)

target_link_libraries(AoCexercise4
    PRIVATE m
)

target_compile_features(AoCexercise4
    PRIVATE cxx_std_98
)