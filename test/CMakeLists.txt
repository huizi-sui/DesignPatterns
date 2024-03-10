
set(MAIN_FACTORY_SRC main_factory.cpp
             ../src/Factory.cpp
)

set(MAIN_ABSTRACT_FACTORY_DIRS main_abstract_factory.cpp ../src/AbstractFactory.cpp)

add_executable(main_factory ${MAIN_FACTORY_SRC})
add_executable(main_abstract_factory ${MAIN_ABSTRACT_FACTORY_DIRS})
add_executable(main_singleton main_singleton.cpp)
add_executable(main_builder main_builder.cpp)