add_executable(AoCexercise5)

target_sources(AoCexercise5
    PRIVATE exercise5.c
)

target_link_libraries(AoCexercise5
    PRIVATE m
)

target_compile_features(AoCexercise5
    PRIVATE cxx_std_98
)