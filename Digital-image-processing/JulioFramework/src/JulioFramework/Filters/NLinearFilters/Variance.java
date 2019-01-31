/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JulioFramework.Filters.NLinearFilters;

import Catalano.Imaging.FastBitmap;
import Catalano.Imaging.IApplyInPlace;

/**
 *
 * @author juliocmalvares
 */
public class Variance implements IApplyInPlace{
    public int raio;
    private int lines;
    
    public Variance() {
        this.raio = 1;
        this.lines = 3;
    }
    
    public Variance(int raio) {
        this.raio = raio;
        this.lines = (2*this.raio)+1;
    }
    
    @Override
    public void applyInPlace(FastBitmap fb) {
        int[] medias = new int[3];
        int[] variances = new int[3];
        FastBitmap fb_copy = new FastBitmap(fb);
        fb.Clear();
        int counter = 0;
        int xline = 0, yline = 0;
        
        for (int i = 0; i < fb_copy.getHeight(); i++) {
            for (int j = 0; j < fb_copy.getWidth(); j++) {
                counter = 0;
                
                for (int k = 0; k < this.lines; k++) {
                    xline = i + (k-this.raio);
                    for (int l = 0; l < this.lines; l++) {
                        yline = j + (l - this.raio);
                        if(xline >= 0 && xline < fb.getHeight() && yline >= 0 && yline < fb.getWidth()){
                            medias[0] += fb_copy.getRed(xline, yline);
                            medias[1] += fb_copy.getGreen(xline, yline);
                            medias[2] += fb_copy.getBlue(xline, yline);
                            counter ++;
                        }
                    }
                }
                
                medias[0] /= counter;
                medias[1] /= counter;
                medias[2] /= counter;
                
                
                for (int k = 0; k < this.lines; k++) {
                    xline = i + (k - this.raio);
                    for (int l = 0; l < this.lines; l++) {
                        yline = j + (l - this.raio);
                        if(xline >= 0 && xline < fb.getHeight() && yline >= 0 && yline < fb.getWidth()){
                            variances[0] += (int) Math.pow(fb_copy.getRed(i, j) - medias[0], 2);
                            variances[1] += (int) Math.pow(fb_copy.getGreen(i, j) - medias[1], 2);
                            variances[2] += (int) Math.pow(fb_copy.getBlue(i, j) - medias[2], 2);
                        }
                    }
                }
                
                variances[0] /= counter -1;
                variances[1] /= counter -1;
                variances[2] /= counter -1;
                
                if(variances[0] < 0) variances[0] = 0;
                if(variances[1] < 0) variances[1] = 0;
                if(variances[2] < 0) variances[2] = 0;
                if(variances[0] > 255) variances[0] = 255;
                if(variances[1] > 255) variances[1] = 255;
                if(variances[2] > 255) variances[2] = 255;
                
                fb.setRGB(i,j,variances[0], variances[1], variances[2]);
            }
        }
    }
    
}
