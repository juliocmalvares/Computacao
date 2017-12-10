#ifndef JANTAR_H_INCLUDED
#define JANTAR_H_INCLUDED

#include <cstdlib>
#include <ctime>
template < class T >
class Jantar{
    public:
        Hashi<int> *hashis[5];
        Filosofo<int> *filosofos[5];

        Jantar(){
            this->instancia_dados();
        }
        T instancia_dados();
        T jantar();

};

template < class T >
T Jantar<T>::instancia_dados(){
	for (int i = 0; i < 5; i++){
		this->hashis[i] = new Hashi<int>();
		this->hashis[i]->set_indice(i);
		this->filosofos[i] = new Filosofo<int>();
		this->filosofos[i]->meu_indice = i;
		if(i == 0){
			this->filosofos[0]->hashi2 = 4;
			this->filosofos[0]->hashi1 = 0;
		}else{
			this->filosofos[i]->hashi2 = (i-1);
			this->filosofos[i]->hashi1 = i;
		}
	}
}


template < class T >
T Jantar<T>::jantar(){
    int tempo_c, tempo_p;
    srand(time(NULL));
    int aux;
    aux = rand()%5;
    while(1){
        while(this->filosofos[aux]->bloqueado() == 0){ //nao esta bloqueado
            tempo_c = this->filosofos[aux]->comer(this->hashis);
            if(tempo_c != -1){
                cout << "\nFilosofo " << this->filosofos[aux]->meu_indice << " comendo por " << tempo_c << "segundos" << endl;
                //this->filosofos[aux]->set_bloqueio(1);
                this_thread::sleep_for(chrono::seconds(tempo_c));
            }else{
                tempo_p = this->filosofos[aux]->pensar(this->hashis);
                cout << "\nFilosofo " << this->filosofos[aux]->meu_indice << " pensando por " << tempo_p << "segundos" << endl;
                //this->filosofos[aux]->set_bloqueio(1);
                this_thread::sleep_for(chrono::seconds(tempo_p));
            }
        }
        aux = rand()%5;
    }


/*






    int tempo_comer, tempo_pensar;
    for(;;){
        for(int aux = 0; aux < 5; aux++){
            //cout << "voltei pro inicio do for" << endl;
            if(this->filosofos[aux]->bloqueado() == 0){
                tempo_comer = filosofos[aux]->comer(this->hashis);
                if(tempo_comer == -1){
                    tempo_pensar = filosofos[aux]->pensar(this->hashis);
                    filosofos[aux]->set_bloqueio(1);
                    cout << "Filosofo " << filosofos[aux]->meu_indice << " pensando por " << tempo_pensar << " segundos" << endl;
                   // this_thread::sleep_for(chrono::seconds(tempo_pensar));
                }else{
                    filosofos[aux]->set_bloqueio(1);
                    cout << "Filosofo " << filosofos[aux]->meu_indice << " comendo por " << tempo_comer << " segundos" << endl;
                   // this_thread::sleep_for(chrono::seconds(tempo_comer));
                }

            }
        }
        //cout << "sai do for" << endl;
        continue;
    }

    */
}


#endif // JANTAR_H_INCLUDED
