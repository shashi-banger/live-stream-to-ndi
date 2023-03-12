
#include "config.h"

namespace config {

std::string  input_stream;

std::string get_input_stream()
{
    return input_stream;
}

void set_input_stream(std::string _input_stream)
{
    input_stream = _input_stream;
}

}