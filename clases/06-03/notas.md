# Clase del 3 de Junio

## Variables como argumentos

Se pueden pasar funciones como argumentos a otras funciones

Ejemplo:
```cpp
int sum (int a, int b) {
  return a + b;
}

int loop(int c, int x(int, int)) {
  int acc = 0;
  for (int i = 0; i < 5; i++) {
    acc = x(acc, c);
  }
  return acc;
}
```

## Templates

Permiten usar tipos "dinamicos" en funciones:
```cpp
template<typename T>
void f(T a) {
  //...
}

int main () {
  // Se pasa el tipo al llamarla.
  f<int>(1);
  f<string>("abc");
  return 0;
}
```


