int factIt(int n, int F, int i){
if(i <= n){
    F *=i;
    return factIt(n,F,i);
}
return F;
}

int fact(int n){
    return factIt(n,1,1);
}



int euclide(int a, int b){
    
}

