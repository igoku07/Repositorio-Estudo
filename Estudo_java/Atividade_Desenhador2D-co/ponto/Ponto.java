package ponto;


/**
 * Escreva uma descrição da classe Ponto aqui.
 * 
 * @author (seu nome) 
 * @version (um número da versão ou uma data)
 */
public class Ponto
{
    private double x;
    private double y;
    
    public Ponto(double x,double y)
    {
        setX(x);
        setY(y);
    }
    
    public Ponto()
    {
        setX(0);
        setY(0);
    }
    
    public void setX(double x)
    {
        this.x = x;
    }
    
    public void setY(double y)
    {
        this.y = y;
    }
    
    public double getX()
    {
        return this.x;
    }
    
    public double getY()
    {
        return this.y;
    }
    
    public String toString()
    {
        return " X: " + getX() + " Y: " + getY();
    }
    
    public double calcularDistancia(Ponto p){
        //Distancia entre dois pontos
        double d = Math.sqrt(Math.pow(p.getY()-getY(), 2) + Math.pow(p.getX()-getX(), 2));
        return(d);
    }
}