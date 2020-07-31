#include <eosiolib/capi/eosio/action.h>
#include <hello.hpp>

[[eosio::action]]
void hello::hi( name nm ) {
   print_f("Name : %\n", nm);
}

[[eosio::action]]
void hello::check( name nm ) {
   print_f("Name : %\n", nm);
   eosio::check(nm == "hello"_n, "check name not equal to `hello`");
}

[[eosio::action]]
void hello::checkwithrv( name nm ) {
   print_f("Name : %\n", nm);

   std::vector<std::string> results;
   if (nm == "hello"_n) {
      results.push_back("0");
      results.push_back("validation has passed");
   }
   else {
      results.push_back("1");
      results.push_back("name not equal to `hello`");
   }

   const auto& packed_results = eosio::pack(results);
   set_action_return_value((void*)packed_results.data(), packed_results.size());
}
