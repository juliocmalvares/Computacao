/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JulioFramework;

import Catalano.Imaging.FastBitmap;
import Catalano.Imaging.Filters.BlobsFiltering;
import Catalano.Imaging.Filters.Grayscale;
import Catalano.Imaging.Tools.Blob;
import Catalano.Imaging.Tools.BlobDetection;
import java.util.List;
import javax.swing.JOptionPane;

/**
 *
 * @author juliocmalvares
 */
public class Ocr {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        FastBitmap imagem = new FastBitmap("/home/juliocmalvares/Documentos/8 Periodo/PDI/Imagens/Placas/1.jpg");
        Grayscale gr = new Grayscale();
        gr.applyInPlace(imagem);

        BlobDetection bf = new BlobDetection();
        List<Blob> ls = bf.ProcessImage(imagem);
        System.out.println(ls.size());
        //JOptionPane.showMessageDialog(null, imagem.toIcon());
    }
    
}
