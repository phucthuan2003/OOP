        Vecto(const Vecto &x){
            n = x.n;
            elements = new int[n];
            for(int i=0 ; i<n ; i++ ){
                elements[i] = x.elements[i];
            }
        }
        Vecto &operator = (const Vecto &x){
            if(this != &x){
                delete []elements;
                n = x.n;
                elements = new int[n];
                for(int i=0 ; i<n ; i++){
                    elements[i] = x.elements[i];
                }
            }
            return *this;
        }