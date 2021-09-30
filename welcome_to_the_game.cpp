#include <iostream>
#include <allegro.h>
 
int main() 
{   
    // inicializa el entorno del allegro
    allegro_init();
    install_keyboard();
    
    // se establece la resolucion grafica
    // modo ventana, 320x240
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1024, 768, 0, 0);
    
    // se crea buffer para contener todo lo que se muestra en nuestra ventana
    // por eso se crea con la misma dimension que la resolucion
    BITMAP *buffer = create_bitmap(1024, 768);
    // borra la imagen, rellenandola con un color
    clear_to_color(buffer, 0x000000);
    FONT *font = load_font ("font16.pcx", NULL, NULL);
    
    textout_centre_ex(buffer, font, "Welcome to the HANGMAN game!", 512, 200, 0xfdfefe, 0x000000); // muestra un texto, en una posicion  x, y con 512,200 para el muñeco
    
    // Vuelca el contenido de nuestra imagen sobre la pantalla para mostrarlo   
    blit(buffer, screen, 0, 0, 0, 0, 1024, 768);
    line(screen,250,580,650,580, 0xfdfefe); //plataforma
    line(screen,600,580,600,300, 0xfdfefe); //palo vertical
    line(screen,600,300,450,300, 0xfdfefe); //palo superior
    line(screen,450,300,450,340, 0xfdfefe); //cuerda
	circle(screen,450,370,30,  0xa569bd); //cabeza
    line(screen,450,400,450,470, 0xa569bd); //tronco
    line(screen,360,420,540,420, 0xa569bd); //brazos
    line(screen,450,470,400,540, 0xa569bd); //piernas
	line(screen,450,470,500,540, 0xa569bd); 
    
    // para realizar una pausa, espera a que se pulse una tecla
    readkey();
    while(!key[KEY_ESC]){
	}
    allegro_exit();
    return 0;
    
}
END_OF_MAIN();

