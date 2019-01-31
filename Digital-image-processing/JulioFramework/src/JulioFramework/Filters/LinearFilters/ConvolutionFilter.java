package JulioFramework.Filters.LinearFilters;

import Catalano.Imaging.FastBitmap;
import Catalano.Imaging.IApplyInPlace;


/**
 *
 * @author juliocmalvares
 */

public class ConvolutionFilter implements IApplyInPlace{
    public int[][] kernel;
    public int peso;

    public ConvolutionFilter(int[][] kernel) {
        this.kernel = kernel;
        for (int i = 0; i < this.kernel.length; i++) {
            for (int j = 0; j < this.kernel.length; j++) {
                this.peso+= this.kernel[i][j];
            }
        }
        this.peso = peso == 0 ? 1 : this.peso;
    }

    public void setKernel(int[][] kernel) {
        this.kernel = kernel;
    }
    
    @Override
    public void applyInPlace(FastBitmap fb) {
        FastBitmap fb_copy = new FastBitmap(fb);
        fb.Clear();
        fb_copy.toGrayscale();
        fb.toGrayscale();

        for (int i = 0; i < fb.getHeight() - this.kernel.length; i++) {
            for (int j = 0; j < fb.getWidth() - this.kernel[0].length; j++) {
                double centroit = 0;
                for (int k = 0; k < this.kernel.length; k++) {
                    for (int l = 0; l < this.kernel[0].length; l++) {
                        centroit += fb_copy.getGray(i+k,j+l) * this.kernel[k][l];
                    }
                }
                
                centroit /= this.peso;
                if(centroit > 255) centroit = 255;
                else if(centroit <= 0) centroit = 1;
                
                fb.setGray(i, j, (int)centroit);
            }
        }
    }
    
}
