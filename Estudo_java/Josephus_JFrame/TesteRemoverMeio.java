
/**
 * Escreva uma descrição da classe TesteRemoverMeio aqui.
 * 
 * @author (seu nome) 
 * @version (um número da versão ou uma data)
 */
import InterfaceListas.*;
public class TesteRemoverMeio
{
    public static void main(){
        
        IListaLigada l;
        l = new ListaLigadaCircular();
        
        l.inserirFim(2);
        l.inserirFim(3);
        l.inserirFim(4);
        l.inserirFim(5);
        l.inserirFim(6);
        l.inserirFim(7);
        
        l.inserirFim(8);
        l.inserirFim(9);
        l.inserirFim(10);
        l.inserirInicio(1);
        
        System.out.println("Lista: " + l);
        
        l.removerMeio(11);
        
        System.out.println("Lista: " + l);
        
        l.removerMeio(3);
        
        System.out.println("Lista: " + l);
        
        l.removerMeio(3);
        
        System.out.println("Lista: " + l);
    }
}