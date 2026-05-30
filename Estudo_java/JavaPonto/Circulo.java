

public class Circulo
{
    Ponto P;
    double raio;
    
    public Circulo(Ponto P,double raio)
    {
        this.P = P;
        this.raio = raio;
    }
    
    double calcularArea()
    {
        double A = Math.PI * raio * raio;
        return A;
    }
    
    double calcularPerimetro()
    {
        double P = 2 * Math.PI * raio;
        return P;
    }
    
    boolean verificarPonto(Ponto T)
    {   
        boolean O = false;
        
        double D = Math.sqrt( (T.getX() - P.getX())*(T.getX() - P.getX())+(T.getY() - P.getY())*(T.getY() - P.getY()) );
        if(D <= raio)
        {
            O = true;           
        }
        return O;
    }
    
    public String toString()
    {
        return "Àrea do Circulo: " + calcularArea() + "\nCalcular Perimetro: " +  calcularPerimetro() + "\nRaio: " + this.raio;
    }
    
}