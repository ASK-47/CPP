//https://youtu.be/hwD06FNXndI?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//recursive_lambdas_deducing_this

int main() {
    //auto fuctorial =[]<typename Self>(this const Self& self, int val){//deducing this C++23
    auto fuctorial =[](this const auto self, int val){//Deducing this C++23 + CTAD C++20
        if(val==1) return 1;
        else return val* self(val-1);
    };
    return fuctorial(6);
}