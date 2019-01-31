/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JulioFramework.Filters;

import Catalano.Imaging.FastBitmap;
import Catalano.Imaging.IApplyInPlace;

/**
 *
 * @author juliocmalvares
 */
public class AutomaticContrastFilter implements IApplyInPlace{
    public int rmax = 0, rmin = 1000, gmax = 0, gmin = 1000, bmax = 0, bmin = 1000;
    public AutomaticContrastFilter() {
    }

    @Override
    public void applyInPlace(FastBitmap fb) {
        int rvalue, gvalue, bvalue;
        for (int i = 0; i < fb.getHeight(); i++) {
            for (int j = 0; j < fb.getWidth(); j++) {
                
                this.rmax = (this.rmax > fb.getRed(i,j)) ? this.rmax : fb.getRed(i, j);
                this.gmax = (this.gmax > fb.getGreen(i,j)) ? this.gmax : fb.getGreen(i, j);
                this.bmax = (this.bmax > fb.getBlue(i,j)) ? this.bmax : fb.getBlue(i, j);
                
                this.rmin = (this.rmin < fb.getRed(i,j)) ? this.rmin : fb.getRed(i, j);
                this.gmin = (this.gmin < fb.getGreen(i,j)) ? this.gmin : fb.getGreen(i, j);
                this.bmin = (this.bmin < fb.getBlue(i,j)) ? this.bmin : fb.getBlue(i, j);
            }
        }
        System.out.printf("Max: %d %d %d\n", this.rmax, this.gmax, this.bmax);
        System.out.printf("Min: %d %d %d\n", this.rmin, this.gmin, this.bmin);
        for (int i = 0; i < fb.getHeight(); i++) {
            for (int j = 0; j < fb.getWidth(); j++) {             
                rvalue = (fb.getRed(i,j) - this.rmin) * (255/(this.rmax - this.rmin));
                gvalue = (fb.getGreen(i,j) - this.gmin) * (255/(this.gmax - this.gmin));
                bvalue = (fb.getBlue(i,j) - this.bmin) * (255/(this.bmax - this.bmin));
                
                rvalue = (rvalue > 255) ? 255 : rvalue;
                rvalue = (rvalue < 0) ? 1 : rvalue;
                
                gvalue = (gvalue > 255) ? 255 : gvalue;
                gvalue = (gvalue < 0) ? 1 : gvalue;
                
                bvalue = (bvalue > 255) ? 255 : bvalue;
                bvalue = (bvalue < 0) ? 1 : bvalue;
                
                fb.setRed(i,j, rvalue);
                fb.setGreen(i,j, gvalue);
                fb.setBlue(i,j, bvalue);
                
            }
        }
    }
    
}
