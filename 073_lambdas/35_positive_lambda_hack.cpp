//https://youtu.be/fYd84StM5OI?list=PLs3KjaCtOwSaJfzcaQ5RpcDIx9PTe2bBP
//positive_lambda_hack


int main() {
    (+[](){})();
    (+[]{})();
    (+[]()->void{})();

    //pointer inside => + == cast to to pointer  == static_cast<void(*)()> 
    (****+[]()->void{})();
    (&*&*&*+[]()->void{})();/ref/dered/ref/deref...

}