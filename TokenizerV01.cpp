#include <iostream>
#include <random>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

string token_gen(int lenght) {
    const string CHAR = "ABCDEFGH0123456789";

    random_device rd;
    mt19937 code_generator(rd());

    uniform_int_distribution<> code_randomizer(0, CHAR.size() - 1);

    string radom;
    for (int i = 0; i < lenght; i++) {
        radom += CHAR[code_randomizer(code_generator)];
    }
    return radom;
}

int main(){
	string tokens[20];
	string user_token;
	string passwd;
	string usr_passwd = "admin";

	int last_array_element = (sizeof(tokens) / sizeof(tokens)) - 1;

	for (int i = 0; i < 20; i++) {
		int length = 10; tokens[i] = token_gen(length);
    	}

	cout << "Digite a senha: ";
	std::cin >> passwd;

	if(passwd.compare(usr_passwd) != 0 ){
	exit(1);
	}


    	for (int i = 0; i < 20; i++) {
		cout << tokens[i] << endl;
    	}

	for(int i = 0; i < 10; i++){
	std::cout << "Digite o token: " << std::endl;
	std::cin >> user_token;

	auto it = find(begin(tokens), end(tokens), user_token);
	if(it != end(tokens)){
		cout<<"Token Válido"<<endl;
		*it = "";
		for(int i = 0; i < 20; i++){
			if(!tokens[i].empty()){
			cout<<tokens[i]<<endl;
			}
		}
	}else{
	cout<< "Erro: Token inválido (O token pode ser usado apenas uma vez)"<<endl;
	}
	}
}

