/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jfacerecognition;

import Catalano.Imaging.FastBitmap;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author juliocmalvares
 */
public class PGMReader {
    private PGMIO pgm;
    private List<FastBitmap> images;
    private List<File> arqs;
    
    
    public PGMReader(){
        this.arqs = new ArrayList<>();
        this.images = new ArrayList<>();
    }
    
    public List<FastBitmap> read(List<File> arq) throws IOException{
        this.arqs = arq;
        int[][] dados;
        for(int i = 0; i < this.arqs.size(); i++){
            dados = PGMIO.read(this.arqs.get(i));
            this.images.add(new FastBitmap(dados));
        }
        return this.images;
    }
    
}
