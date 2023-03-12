
#include <boost/program_options.hpp>
namespace po = boost::program_options;
#include <string>
#include <iostream>
#include <common/config.h>

void get_env_options(int ac, char* av[])
{
   po::options_description options("Live stream to NDI");
   options.add_options()
      ("help,h", "Print help messages") 
      ("input_stream,i", po::value<std::string>(), "Input udp stream url")
      ("output_ndi,o", po::value<std::string>(), "Iutput NDI stream name")
      ;

   po::variables_map vm;
   po::store(po::command_line_parser(ac, av).
          options(options).run(), vm);
   po::notify(vm);

   if (vm.count("input_stream"))
   {
      std::string input_stream = vm["input_stream"].as<std::string>();
      std::cout << "Input stream: " << input_stream << std::endl;
      std::cout << "Input stream: " << vm["input_stream"].as<std::string>() << std::endl;
      config::set_input_stream(std::string(vm["input_stream"].as<std::string>()));
   }

   if (vm.count("output_ndi"))
   {
      std::cout << "Output NDI stream: " << vm["output_ndi"].as<std::string>() << std::endl;
   }

}

int main(int ac, char* av[])
{
   get_env_options(ac,av);

   return 0;
}