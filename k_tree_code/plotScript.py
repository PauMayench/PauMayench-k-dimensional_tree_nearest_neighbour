'''



SI VOLEU FER PLOT DE NOMES ALGUNES DIMENSIONS TREIEU ELS FITXERS DEL DIRECTORI O CANVIEULI EL NOM I JA ANIRA




'''
import matplotlib.pyplot as plt

def on_key(event):
    # Close the plot only when the 'Enter' key is pressed
    if event.key == 'enter':
        plt.close(event.canvas.figure)

def read_data_from_file(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()

    mida = []
    ktree = []
    rktree = []
    sktree = []

    for i, line in enumerate(lines):
        if "MIDA:" in line:
            mida.append(int(line.split()[1]))

            # Assuming the next three lines always follow the format: KTREE, RKTREE, SKTREE
            ktree.append(int(lines[i+1].split()[2]))
            rktree.append(int(lines[i+2].split()[2]))
            sktree.append(int(lines[i+3].split()[2]))

    return mida, ktree, rktree, sktree

# Read data
paths = ["2.out","3.out","4.out","5.out","6.out","7.out","8.out" ]
try:
    for path in paths:
        try:
            mida, ktree, rktree, sktree = read_data_from_file("out/tempsDim"+path)

            # Plotting the data
            plt.plot(mida, ktree, 'o-', label='KTREE')
            plt.plot(mida, rktree, 's-', label='RKTREE')
            plt.plot(mida, sktree, '^-', label='SKTREE')

            # Setting the x-axis to logarithmic scale
            plt.xscale('log')

            # Adding title and labels
            plt.title("DIMENSIÓ {}: Cost vs MIDA".format(path[0]))
            plt.xlabel('MIDA')
            plt.ylabel('Cost')
            plt.legend()

            # Display the plot
            plt.grid(True, which="both", ls="--", c='0.7')
            plt.gcf().canvas.mpl_connect('key_press_event', on_key)

            # Show the plot (non-blocking)
            plt.show()
        except:
            pass

except KeyboardInterrupt:
    # Close all open plots when Ctrl+C is pressed
    plt.close('all')