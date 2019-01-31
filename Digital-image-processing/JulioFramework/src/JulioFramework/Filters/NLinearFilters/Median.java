/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JulioFramework.Filters.NLinearFilters;

import Catalano.Imaging.Color;
import Catalano.Imaging.FastBitmap;
import Catalano.Imaging.IApplyInPlace;
import java.util.Arrays;

/**
 *
 * @author juliocmalvares
 */
public class Median implements IApplyInPlace{
    public int raio;
    public int lines;
    
    public Median(){
        this.raio = 1;
        this.lines = 3;
    }
    public Median(int raio){
        this.raio = raio;
        this.lines = (2*this.raio)+1;
    }
    @Override
    public void applyInPlace(FastBitmap fb) {
        FastBitmap fb_copy = new FastBitmap(fb);
        fb.Clear();
        int xline, yline;
        int counter = 0;
        int[] vecRed = new int[this.lines*this.lines];
        int[] vecBlue = new int[this.lines*this.lines];
        int[] vecGreen = new int[this.lines*this.lines];
        int meio = 0;
        
        for (int i = 0; i <= fb.getHeight() - this.raio; i++) {
            for (int j = 0; j <= fb.getWidth() - this.raio; j++) {
                counter = 0;
                for (int k = 0; k < this.lines; k++) {
                    xline = i + (k-this.raio);
                    for (int l = 0; l < this.lines; l++) {
                        yline = j + (l - this.raio);
                        if(xline >= 0 && xline < fb.getHeight() && yline >= 0 && yline < fb.getWidth()){
                            vecRed[counter] = fb_copy.getRed(xline, yline);
                            vecGreen[counter] = fb_copy.getGreen(xline, yline);
                            vecBlue[counter] = fb_copy.getBlue(xline, yline);                        
                            counter++;
                        }
                    }
                }
                Arrays.sort(vecRed, 0, counter);
                Arrays.sort(vecGreen, 0, counter);
                Arrays.sort(vecBlue, 0, counter);
                
                meio = counter/2;
                fb.setRGB(i, j, vecRed[meio], vecGreen[meio], vecBlue[meio]);
            }
        }
    }
    
}
