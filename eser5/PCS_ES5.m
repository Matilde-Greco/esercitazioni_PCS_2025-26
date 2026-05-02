% Dimensioni del vettore (N)
n = [0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100];

% --- DATI DELLA TUA TABELLA LATEX ---
bubble    = [3e-09, 5.06e-07, 2.24e-06, 5.81e-06, 6.64e-06, 8.23e-06, 1.36e-05, 1.75e-05, 1.75e-05, 1.92e-05, 2.27e-05];
insertion = [2e-09, 1.87e-07, 4.68e-07, 6.18e-07, 1.67e-06, 9.01e-07, 3.10e-06, 1.77e-06, 2.30e-06, 1.83e-06, 2.42e-06];
selection = [3e-09, 4.83e-07, 1.45e-06, 2.61e-06, 4.65e-06, 4.67e-06, 4.23e-06, 4.75e-06, 8.04e-06, 7.36e-06, 8.54e-06];
quick     = [5e-09, 3.81e-07, 9.39e-07, 1.63e-06, 1.84e-06, 2.86e-06, 6.10e-06, 3.43e-06, 4.07e-06, 3.43e-06, 4.28e-06];
merge     = [5e-09, 1.90e-06, 4.09e-06, 6.01e-06, 9.44e-06, 6.02e-06, 5.12e-06, 5.79e-06, 6.93e-06, 7.12e-06, 7.70e-06];
hybrid    = [2e-09, 2.17e-07, 7.73e-07, 9.68e-07, 1.57e-06, 2.11e-06, 1.73e-06, 2.20e-06, 2.19e-06, 2.61e-06, 2.90e-06];

% Per std_sort, siccome non era in tabella, usiamo i valori del tuo ultimo codice 
% che sono coerenti con una scala corretta
std_sort  = [2.01e-9, 1.66e-7, 3.79e-7, 7.78e-7, 1.09e-6, 1.15e-6, 1.44e-6, 1.95e-6, 2.11e-6, 2.30e-6, 2.75e-6];

% --- CREAZIONE DEL GRAFICO ---
figure('Color', 'w');
hold on;

plot(n, bubble,    '-o', 'LineWidth', 1.5, 'DisplayName', 'Bubble Sort');
plot(n, selection, '-d', 'LineWidth', 1.5, 'DisplayName', 'Selection Sort');
plot(n, insertion, '-s', 'LineWidth', 2.0, 'DisplayName', 'Insertion Sort (Best Quad)');
plot(n, merge,     '--x', 'LineWidth', 1.5, 'DisplayName', 'Merge Sort');
plot(n, quick,     '-^',  'LineWidth', 2.0, 'DisplayName', 'Quick Sort');
plot(n, hybrid,    '-*',  'LineWidth', 2.5, 'Color', [0 0.7 0], 'DisplayName', 'Quicksort Hybrid');
plot(n, std_sort,  ':k',  'LineWidth', 2.0, 'DisplayName', 'std::sort (C++)');

% Formattazione
grid on;
set(gca, 'YScale', 'log'); 
xlabel('Dimensione del vettore (N)');
ylabel('Tempo di esecuzione (secondi)');
title('Benchmark Algoritmi di Ordinamento (N=0 a 100)');
legend('Location', 'bestoutside');
text(40, 1e-6, ' \leftarrow Possibile n0', 'FontSize', 10, 'Color', 'r');