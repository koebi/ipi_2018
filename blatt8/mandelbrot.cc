#include "fcpp.hh"
#include "save_image.hh"

//// Teil a)

// Datentyp fuer komplexe Zahlen bestehend aus Real- und Imaginaerteil
struct Complex
{
  float real;
  float imag;
};

// Erzeuge eine komplexe Zahl mit Realteil re und Imaginaerteil im
Complex erzeuge_complex( float re, float im )
{
  Complex t;
  t.real = re; t.imag = im;
  return t;
}

// Syntaktischer Zucker
float real( Complex q ) { return q.real; }
float imag( Complex q ) { return q.imag; }

// Summiert zwei komplexe Zahlen p und q und schreibt das Ergebnis in p
void add_complex( Complex& p, Complex q )
{
  float r = real(p) + real(q);
  float i = imag(p) + imag(q);
  p.real = r;
  p.imag = i;
}

// Multipliziert zwei komplexe Zahlen p und q und schreibt das Ergebnis in p
void multiply_complex( Complex& p, Complex q )
{
  float real_ = real(p)*real(q) - imag(p)*imag(q);
  float imag_ = real(p)*imag(q) + imag(p)*real(q);
  p.real = real_;
  p.imag = imag_;
}

// Berechnet einen Schritt der Mandelbrot-Folge fuer die komplexe Zahl
// c, gegeben dem aktuellen Folgenelement z und schreibt das Ergebnis in z
void schritt( Complex& z, Complex c )
{
  multiply_complex(z, z);
  add_complex(z, c);
}

// Betrag einer komplexen Zahl
float betrag(Complex z) {
  float r = real(z);
  float i = imag(z);
  return std::sqrt(r*r + i*i);
}

// Betrag des n-ten Elements der Mandelbrot-Folge  zu c
float trajektorie( Complex c, int n)
{
  Complex current = erzeuge_complex(0.0, 0.0);
  for(int i = 0; i < n; ++i) {
    schritt(current, c);
  }
  return betrag(current);
}

//// Teil b)

// Datentyp fuer Bilder der Hoehe H und Breite W
struct Image {
  int H, W;
  float* pixel;
};

// Erzeugt ein neues Bild der Hoehe H und Breite W
Image create_image(int H, int W) {
  // TODO Erzeugen Sie ein Bild der entsprechenden Hoehe und Breite und
  // allokieren Sie den benoetigten Speicherplatz fuer die Pixel dynamisch
  Image I;
  I.H = H;
  I.W = W;
  I.pixel = new float[H*W];
  return I;
}

// Wert eines Bildes I in der i-ten Zeile und j-ten Spalte
float get_pixel(Image& I, int i, int j) {
  return I.pixel[i*I.W + j];
}

// Setzt den Wert von Bild I in der i-ten Zeile und j-ten Spalte auf den
// Wert value
void set_pixel(Image& I, int i, int j, float value) {
  I.pixel[i*I.W + j] = value;
}

//// Teil c)

// Initialisiert die Werte zweier Bilder x_coords und y_coords, so dass die
// Pixel den x und y Koordinaten eines Gitters (x_min, x_max, y_min, y_max)
// entsprechen. D.h. links oben entspricht (x_min, y_min), rechts oben
// (x_max, y_min), links unten (x_min, y_max) und rechts unten (x_max,
// y_max)
void init_grid(Image* x_coords, Image* y_coords,
                float x_min, float x_max,
                float y_min, float y_max) {
  int H = x_coords->H;
  int W = x_coords->W;
  for(int i = 0; i < H; ++i) {
    float y = y_min + float(i) / (H-1) * (y_max - y_min);
    for(int j = 0; j < W; ++j) {
      float x = x_min + float(j) / (W-1) * (x_max - x_min);
      set_pixel(*x_coords, i, j, x);
      set_pixel(*y_coords, i, j, y);
    }
  }
}

// Reduziert Hoehe und Breite eines Bildes I um einen Faktor 2.
void downsample(Image& image) {
  int new_H = image.H / 2;
  int new_W = image.W / 2;
  float* new_pixel = new float[new_H*new_W];
  for(int i = 0; i < new_H; ++i) {
    int old_i = 2*i;
    for(int j = 0; j < new_W; ++j) {
      int old_j = 2*j;
      new_pixel[i*new_W + j] = get_pixel(image, old_i, old_j);
    }
  }
  delete image.pixel;
  image.pixel = new_pixel;
  image.H = new_H;
  image.W = new_W;
}

int main()
{
  int H = 256;
  int W = 256;
  int N = 100;
  float xmin = -1.5,
        xmax =  0.5,
        ymin = -1.0,
        ymax =  1.0;

  Image x_coords = create_image(H, W);
  Image y_coords = create_image(H, W);
  init_grid(&x_coords, &y_coords, xmin, xmax, ymin, ymax);
  save_image("x.png", x_coords.pixel, x_coords.W, x_coords.H);
  save_image("y.png", y_coords.pixel, y_coords.W, y_coords.H);

  Image bild = create_image(H, W);
  for(int i = 0; i < H; ++i) {
    for(int j = 0; j < W; ++j) {
      float x = get_pixel(x_coords, i, j);
      float y = get_pixel(y_coords, i, j);
      Complex c = erzeuge_complex(x, y);
      float value = trajektorie(c, N);

      set_pixel(bild, i, j, value);
    }
  }
  save_image("bild.png", bild.pixel, bild.W, bild.H);
  downsample(bild);
  save_image("bild_klein.png", bild.pixel, bild.W, bild.H);
}
