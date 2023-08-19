# https://valerionew.github.io/triennale-elettronica-polimi/

## Come contribuire ![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)

Il repository è così strutturato:

```tree -d -L 2 .
triennale-elettronica-polimi/
├── 1
│   ├── AM1
│   ├── Chimica
│   ├── Fisica1
│   ├── GAL
│   └── Informatica
├── 2
│   ├── AM2
│   ├── ArchCalc
│   ├── DE
│   ├── EEO
│   ├── Elettrotecnica
│   ├── FDA
│   └── FDE
├── 3
│   ├── Analogica
│   ├── CEM
│   ├── Digitale
│   ├── ESS
│   ├── Macchine
│   ├── Microcontrollori
│   ├── Optoelettronica
│   ├── Segnali
│   └── Trasformate
├── 4
│   ├── Analog
│   ├── Electron Devices
│   ├── ElectronicSystems
│   ├── MEMS
│   ├── Prerequisites
│   ├── RFCircuitDesign
│   ├── DICD
│   ├── DESD
│   └── SignalRecovery
├── 5
│   ├── PowerElectronics
│   └── EDFBI
├── TAB1
│   ├── EMC
│   ├── HardwareAccelerators
│   ├── NumericalMethods
│   ├── OpticalMeasurements
│   ├── SensorSystems
│   └── Solid State Physics A
├── TAB2
│   ├── PhotonicDevices
│   └── RFsystems
└── readme-media
```

Nel repository ci sono 3 cartelle: `1`, `2`, `3`, ciascuna relativa a quell'anno di corso, che contengono a loro volta le cartelle dei corsi; un file `index.html` e un file `style.css`. Alla raccolta si accede attraverso la pagina HTML all'indirizzo https://valerionew.github.io/triennale-elettronica-polimi/.

Nella raccolta esistono due tipi di risorse:

- File
- Contenuti esterni (link)

I file possono essere ad esempio: appunti, formulari, schemi. e sono tipicamente inseriti come file quando l'autore non li ha già resi disponibili su internet su un proprio spazio. I contenuti esterni invece sono risorse pubblicate dall'autore altrove, linkate nella pagina HTML. I contenuti esterni possono essere inseriti anche come file "mirror" nel caso la fonte originale diventasse non più disponibile. **È sempre preferibile usare la fonte originale come link primario, ma salvando sempre i file come mirror**.

I file della raccolta devono essere resi disponibili secondo licenze libere, la licenza predefinita del repository è [Creative commons BY-NC-SA-4.0](https://creativecommons.org/licenses/by-nc-sa/4.0/deed.it), che si applica **salvo diversamente specificato** e **salvo i file mirror**.

### Istruzioni generali

Per contribuire alla raccolta dovrai avere un account GitHub. Dovrai creare un **fork** di questo repository, cioè una tua copia personale modificabile. Una volta aggiunto il tuo contributo dovrai creare una **pull request**, così che io possa aggiungere i tuoi cambiamenti al repository principale, da questo viene creata la pagina visibile online.

1. Forka il progetto. Questa è la tua copia personale di questo repository che potrai modificare  
   ![Fork button](/readme-media/fork.jpg)
1. Se hai dei file da aggiungere aggiungili con il drag&drop: naviga nella sottocartella del corso e trascina i file. Ti sarà chiesto di creare un **commit**, questo è il nome che su git hanno i singoli cambiamenti elementari di file. Ricordati di dargli un nome significativo! Per altre informazioni vedi [la sezione sui file](##voglio-aggiungere-un-mio-file-alla-raccolta)  
   ![Commit](/readme-media/upload-commit.jpg)
1. Ora devi aggiungere un link alla risorsa in modo che le persone possano trovarla. Per fare questo dovrai aggiungere un link nel file `index.html`. Apri il file e premi l'icona di modifica  
   ![Edit](/readme-media/file-edit.jpg)  
   Trova ora la sezione del corso e aggiungi una riga del tipo:
   ```
   <li>Appunti di <i>Mario Rossi</i> - <a href="1/Chimica/chimicaRossi.pdf" download>Download</a></li>
   ```
   Oppure:
   ```
   <li>Formulario di <i>Mario Rossi</i> - <a href="https://linkesterno.com/risorsa">Link diretto</a> - <a href="1/Chimica/formulario.pdf" download>Mirror</a></li>
   ```
   Contenente una breve descrizione e uno o più link. Se stai inserendo un link a una risorsa esterna, ricordati di inserire l'asterisco che identifica queste risorse: `<b> (*) </b>`.
   Procedi poi a fare il **commit** esattamente come descritto sopra: ricordati di inserire un nome significativo!
1. Una volta che hai terminato di aggiungere cambiamenti, è il momento di fare la pull request, in questo modo riceverò una notifica che le tue aggiunte sono in attesa di revisione, e potrò intergarle nella pagina. Apri quindi il repository principale e avvia una pull request:  
   ![Pull-request](/readme-media/pull-request.jpg)  
   Qui dovrai selezionare "Comapre across forks" e scegliere come _head repository_ il tuo fork.  
   ![compare](/readme-media/compare.jpg)  
   A questo punto potrai rivedere i tuoi cambiamenti e procedere con l'apertura della pull request. I cambiamenti proposti verranno controllati e rivisti e aggiunti al repository principale. Dopo qualche minuto saranno disponibili sulla pagina: https://valerionew.github.io/triennale-elettronica-polimi/

### Voglio aggiungere un mio file alla raccolta

Se possibile **inserisci la licenza nel file**, magari in prima pagina. Se non sai quale scegliere, usa [la predefinita](https://creativecommons.org/licenses/by-nc-sa/4.0/deed.it), è sufficente la dicitura "Rilasciato sotto Creative Commons CC-BY-NC-SA-4.0" unita a un link alla licenza: https://creativecommons.org/licenses/by-nc-sa/4.0/deed.it. Se non riesci a inserirla nel file, specifica la licenza esplicitamente nella **pull request**.

Il nome del file dovrebbe essere qualcosa come `corsoAutore.pdf` o `corsoFormularioAutore.pdf`. Se il tuo contributo è composto da molti file, considera di **creare una sottocartella dentro a quella del corso**.

# Segnala una violazione del copyright:

[![Copyright violation](https://img.shields.io/badge/copyright-violation-red?style=flat)](https://github.com/valerionew/triennale-elettronica-polimi/issues/new?assignees=&labels=Copyright&template=report-violazione-di-copyright.md)

https://github.com/valerionew/triennale-elettronica-polimi/issues/new?assignees=&labels=Copyright&template=report-violazione-di-copyright.md
