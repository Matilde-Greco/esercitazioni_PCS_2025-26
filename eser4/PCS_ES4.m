%dimensione del vettore su asse x 
%tempo impiegato su y

%vettore dimensioni
N = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192];

%tempi
t_bubble    = [1e-06, 1.9e-06, 6.5e-06, 2.1e-05, 0.000107, 0.000504, 0.00142, 0.00576, 0.0106, 0.0318, 0.124, 0.481];
t_selection = [6e-07, 1.5e-06, 4.9e-06, 1.6e-05, 4.5e-05, 0.000230, 0.00078, 0.00171, 0.0033, 0.0138, 0.053, 0.210];
t_insertion = [4e-07, 9e-07, 2e-06, 9.9e-06, 1.8e-05, 0.000150, 0.00029, 0.00078, 0.0016, 0.0066, 0.026, 0.108];
t_std_sort  = [1.5e-06, 2.3e-06, 4.1e-06, 1.1e-05, 2.2e-05, 4.5e-05, 0.00011, 0.00015, 0.0002, 0.0004, 0.001, 0.002];

%faccio il grafico
figure(1);
plot(N, t_bubble, '-o', 'LineWidth', 2); hold on;
plot(N, t_selection, '-s', 'LineWidth', 2);
plot(N, t_insertion, '-d', 'LineWidth', 2);
plot(N, t_std_sort, '-x', 'LineWidth', 2);

grid on;
xlabel('Dimensione del vettore (N)');
ylabel('Tempo di esecuzione (secondi)');
title('Confronto tempi di ordinamento (Scala Lineare)');

%vedi un po' perchè lui lo fa anche in clasa logaritmica e non ho capito
%bene come fare e se bisogna farlo