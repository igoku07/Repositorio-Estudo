/**
 * Classe que representa uma reta definida por dois pontos.
 * 
 * @author (seu nome) 
 * @version (um número da versão ou uma data)
 */
public class Reta
{
    private Ponto P;
    private Ponto I;
 
    /**
     * Construtor para objetos da classe Reta.
     * Toda reta precisa de dois pontos.
     */
    public Reta(Ponto P, Ponto I)
    {
        this.P = P;
        this.I = I;
    }
 
    /**
     * calcularM - calcula o coeficiente angular (M) da reta.
     * Fórmula: M = (Y2 - Y1) / (X2 - X1)
     * 
     * @return m - coeficiente angular
     */
    public double calcularM()
    {
        double m = (P.getP2() - I.getP2()) / (P.getP1() - I.getP1());
        return m;
    }
 
    /**
     * calcularB - calcula o coeficiente linear (B) da reta.
     * Fórmula: B = Y - M*X  (usando um ponto da reta)
     * 
     * @param m - coeficiente angular
     * @return b - coeficiente linear
     */
    public double calcularB(double m)
    {
        // CORRIGIDO: era (m * X) - Y, o certo é Y - (m * X)
        double b = P.getP2() - (m * P.getP1());
        return b;
    }
 
    /**
     * calcularDistancia - calcula a distância de um ponto externo até esta reta.
     * 
     * @param X - ponto externo
     * @return d - distância
     */
    public double calcularDistancia(Ponto X)
    {
        // Coeficiente angular e linear da reta principal
        double Mp = calcularM();
        double Bp = calcularB(Mp);
 
        // CORRIGIDO: inclinação da reta perpendicular é apenas -1/Mp
        double ms = -1.0 / Mp;
 
        // CORRIGIDO: bs = Y - ms*X  (era ms*X - Y)
        double bs = X.getP2() - (ms * X.getP1());
 
        // Ponto de intersecção entre a reta principal e a perpendicular
        double Xi = (bs - Bp) / (Mp - ms);
        double Yi = (Mp * Xi) + Bp;
        Ponto M = new Ponto(Xi, Yi);
 
        // Distância entre o ponto de intersecção e o ponto X
        double dx = M.getP1() - X.getP1();
        double dy = M.getP2() - X.getP2();
        double d = Math.sqrt(dx * dx + dy * dy);
 
        return d;
    }
 
    /**
     * toString - retorna a equação da reta no formato y = Mx + B
     */
    public String toString()
    {
        double M = calcularM();
        double B = calcularB(M);
 
        // CORRIGIDO: exibia o valor Y do ponto em vez de "y"
        if (B >= 0) {
            return "y = " + M + "x + " + B;
        } else {
            return "y = " + M + "x - " + Math.abs(B);
        }
    }
}