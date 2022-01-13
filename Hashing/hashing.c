// Estruturas Basicas 

//Hash que pega o resto para colocar na posição certa do vetor 
int hash1(int key, int size){
    key = key % 100;
    return key % size;
}

int hash2(int key,int size){
    return size - 2 -(key %(size-2));
}

// Inserir
void inserir(int *vet, int x){
    int pos = hash1(vet,x);
    int desl = hash2(vet,x);

    while(vet[pos] != -1){
        pos = (pos+desl)%N;
        vet[pos] = x;
    }

}