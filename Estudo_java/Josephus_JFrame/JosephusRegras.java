import InterfaceListas.*;
import javax.swing.*;
/**
 * Escreva uma descrição da classe JosephusRegras aqui.
 * 
 * @author (seu nome) 
 * @version (um número da versão ou uma data)
 */
public class JosephusRegras extends JFrame
{
    private IListaLigada l;
    private int indiceAlvo;
    private int passo;
    private int posicaoAtual;
    private int tamanhoAtual;
    
    public JosephusRegras(int qtd, int passo){
        this.l = new ListaLigadaCircular();
        for(int i = 1;i <= qtd;i++){
            l.inserirFim(i);
        }
        this.passo = passo;
        this.posicaoAtual = 0;
        this.tamanhoAtual = l.getQtdNos();
    }
    
    public int getTamanho(){
        return tamanhoAtual;
    }
    
    public Object simularJosephus(){
        Object removido = null;        
        if(tamanhoAtual > 1){                        
            indiceAlvo = posicaoAtual + passo - 1;               
            removido = l.removerMeio(indiceAlvo);            
            posicaoAtual = indiceAlvo % tamanhoAtual;             
            tamanhoAtual = l.getQtdNos();            
        }
        return removido;
    }
    
}