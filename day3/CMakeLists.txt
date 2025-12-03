add_executable(AoCexercise3)

target_sources(AoCexercise3
    PRIVATE exercise3.c
)

target_link_libraries(AoCexercise3
    PRIVATE m
)

target_compile_features(AoCexercise3
    PRIVATE cxx_std_98
)