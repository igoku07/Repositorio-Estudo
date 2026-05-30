
public class Aplicação
{
    //
    public static void main(String args[])
    {
        //quero saber se meu ponto merda ta no circulo cooc
        Ponto I = new Ponto(2,5);
        Circulo C = new Circulo(I,10);
        
        Ponto X = new Ponto(20,20);
        C.verificarPonto(X);
        
        System.out.println("" + C);
        
    }
}