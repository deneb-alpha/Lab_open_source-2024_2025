
# Guida al Lavoro su Progetti Open Source con Git e GitHub

Il lavoro sui progetti open source solitamente prevede l'utilizzo di **pull request** per proporre modifiche al codice. Questo processo comporta diversi passaggi fondamentali, a partire dalla configurazione iniziale del sistema fino all'invio delle modifiche. Ecco una guida dettagliata e ben strutturata.

---

## 1. Generare una Chiave SSH (Windows)

Per autenticarti in modo sicuro con GitHub, è necessario generare una coppia di chiavi SSH.

1. Apri il terminale o il prompt dei comandi e usa il seguente comando:
   ```bash
   ssh-keygen -t rsa -b 4096 -C "tuo@email.com"
   ```
   Questo comando:
   - Genera una chiave RSA a 4096 bit.
   - Usa l'email fornita per identificare la chiave.
   - Produce due file:
     - **`nome_chiave`**: la chiave privata.
     - **`nome_chiave.pub`**: la chiave pubblica.

2. Per visualizzare il contenuto della chiave pubblica, usa:
   ```bash
   type nome_chiave.pub
   ```
3. Copia il contenuto della chiave pubblica.

4. Aggiungi la chiave pubblica a GitHub:
   - Vai su **GitHub > Settings > SSH and GPG keys**.
   - Clicca su **New SSH Key**, incolla la chiave e assegna un titolo significativo.

---

## 2. Verifica della Configurazione del Remote

Per verificare i repository Git configurati come remoti, usa:
```bash
git remote -vv
```
Questo comando mostra i dettagli delle connessioni remote. Esempio:
```
origin  git@github.com:deneb-alpha/Lab_open_source-2024_2025.git (fetch)
origin  git@github.com:deneb-alpha/Lab_open_source-2024_2025.git (push)
```
- **`origin`**: il nome del repository remoto.
- **URL**: l'indirizzo SSH per il fetch e il push.

---

## 3. Aggiungere un Remote Fork

Quando si lavora su un progetto open source, è comune creare un **fork** del repository principale su GitHub. Per aggiungere il fork come remoto:
```bash
git remote add forked git@github.com:daaddo/Lab_open_source-2024_2025.git
```
- **`forked`**: il nome assegnato al fork.
- **URL**: l'indirizzo SSH del repository forkato.

Puoi ora distinguere tra il repository originale (`origin`) e il tuo fork (`forked`).

---

## 4. Creazione e Gestione dei Branch

Lavorare su un **branch** separato è essenziale per organizzare le modifiche. Ecco come gestire i branch:

1. **Creare un nuovo branch:**
   ```bash
   git checkout -b nome_branch
   ```
   Questo comando:
   - Crea un nuovo branch chiamato `nome_branch`.
   - Sposta la tua sessione di lavoro sul branch appena creato.

2. **Visualizzare i branch:**
   ```bash
   git branch -vv
   ```
   Mostra tutti i branch locali e le informazioni sul tracking.

3. **Cambiare branch:**
   ```bash
   git checkout nome_branch
   ```

4. **Spingere il branch sul fork:**
   ```bash
   git push -u forked nome_branch
   ```
   Questo comando:
   - Carica il branch `nome_branch` sul tuo fork (`forked`).
   - Configura il branch locale per tracciare quello remoto.

---

## 5. Creare una Pull Request su GitHub

Dopo aver spinto le modifiche al fork, è il momento di creare una **pull request** (PR) per proporre le modifiche al repository originale.

1. Vai al tuo fork su GitHub.
2. Trova il branch appena pushato.
3. Clicca su **Compare & pull request**.
4. Compila:
   - **Titolo**: una descrizione chiara del lavoro svolto.
   - **Descrizione**: dettagli sulle modifiche apportate, perché sono utili e come funzionano.

5. Invia la pull request per revisione.

---

## Alcuni Comandi Utili per Git

- **Clonare un repository:**
  ```bash
  git clone git@github.com:utente/repository.git
  ```
- **Staging e commit delle modifiche:**
  ```bash
  git add .
  git commit -m "Descrizione delle modifiche"
  ```
- **Sincronizzare con il repository originale:**
  ```bash
  git fetch origin
  git merge origin/main
  ```
- **Eliminare un branch locale:**
  ```bash
  git branch -d nome_branch
  ```

---

## Consigli Finali

- **Descrivi chiaramente le PR:** Una pull request ben documentata facilita il lavoro dei revisori.
- **Sincronizzati spesso:** Mantieni il tuo fork aggiornato rispetto al repository originale per evitare conflitti.
