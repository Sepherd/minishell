# mini_shell

You can find example's of mindmap inside the imgs folder (would you like to create our own?)

How to write a Shell:
https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf (THIS)
https://brennan.io/2015/01/16/write-a-shell-in-c/

Manuals:
https://www.gnu.org/software/bash/manual/bash.html
https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html

Useful Github:
https://github.com/madebypixel02/minishell

Wiki:
https://www.codequoi.com/en/creating-and-killing-child-processes-in-c/
https://www.codequoi.com/en/pipe-an-inter-process-communication-method/
https://www.codequoi.com/en/sending-and-intercepting-a-signal-in-c/
https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/
https://www.codequoi.com/en/errno-and-error-management-in-c/

Youtube:
https://www.youtube.com/playlist?list=PLImOlfe0jV6vcI_eC754tzohTttZziVbg (Rendila accessibile via link, io non la vedo)

Per il momento ho inserito il suffisso "-lreadline" sul Makefile in quanto non riesco a farlo partire altrimenti

Ext function:
readline: legge l'input
rl_clear_history: pulisce l'history
rl_on_new_line: dopo in input, notifica al "update routines" che siamo su una new line
rl_replace_line: Sosituisce 
Access: controlla se esiste un file nel path specificato
Fork: Trasforma un processo in due separati(padre/Figlio)
getcwd : acqisisce la directory corrente(PWD)
chdir : cambia la directory (CD)
stat : acquisisce informazioni su un file e li salva su una struttura (https://digilander.libero.it/uzappi/C/librerie/funzioni/stat.html)

execve: esegue un programma specificato in "Pathname", rimpiazzando l'attuale programma in esecuzione con uno nuovo pulito (heap reset, stack, and (initialized and uninitialized) data segments.)
dup2 : duplica il file descriptor(oldfd) con quello specificato in newfd;
pipe : funziona
Opendir, closedir: aprono / chiudono lo stream della directory specificata
perror: produce un messaggio di errore sullo standard error
ioctl: controlla che un numero e' stato scritto sullo specificato device file e se un numero puo' essere letto
getenv: ritorna il valore di un environment
