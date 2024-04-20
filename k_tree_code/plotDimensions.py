'''



SI VOLEU FER PLOT DE NOMES ALGUNES DIMENSIONS TREIEU ELS FITXERS DEL DIRECTORI O CANVIEULI EL NOM I JA ANIRA




'''


import matplotlib.pyplot as plt

def on_key(event):
    # Close the plot only when the 'Enter' key is pressed
    if event.key == 'enter':
        plt.close(event.canvas.figure)

def read_data_from_file(filename, tree_type):
    with open(filename, 'r') as file:
        lines = file.readlines()

    mida = []
    tree_values = []

    for i, line in enumerate(lines):
        if "MIDA:" in line:
            mida.append(int(line.split()[1]))

            # Depending on the tree_type, get the corresponding value
            if tree_type == "KTREE":
                tree_values.append(int(lines[i+1].split()[2]))
            elif tree_type == "RKTREE":
                tree_values.append(int(lines[i+2].split()[2]))
            elif tree_type == "SKTREE":
                tree_values.append(int(lines[i+3].split()[2]))

    return mida, tree_values

# Specify which tree to plot: "KTREE", "RKTREE", or "SKTREE"
tree_types = ["KTREE", "RKTREE", "SKTREE"]
try:
    for tree_type in tree_types:

        # Reading data from files
        paths = ["2.out", "3.out", "4.out", "5.out", "6.out", "7.out", "8.out"]
        labels = ["DIM 2", "DIM 3", "DIM 4", "DIM 5", "DIM 6", "DIM 7", "DIM 8"]
        colors = ['b', 'g', 'r', 'c', 'm', 'y', 'orange']

        plt.figure(figsize=(10,6))

        for path, label, color in zip(paths, labels, colors):
            try:
                mida, tree_values = read_data_from_file("out/tempsDim"+path, tree_type)
                plt.plot(mida, tree_values, 'o-', label=label, color=color)
            except:
                pass

        # Setting the x-axis to logarithmic scale
        plt.xscale('log')

        # Adding title, labels, and legend
        plt.title(f'{tree_type} Cost vs MIDA for Different Dimensions')
        plt.xlabel('MIDA')
        plt.ylabel(f'{tree_type} Cost')
        plt.legend()

        # Displaying the plot
        plt.grid(True, which="both", ls="--", c='0.7')
        plt.gcf().canvas.mpl_connect('key_press_event', on_key)
        plt.show()

except KeyboardInterrupt:
    # Close all open plots when Ctrl+C is pressed
    plt.close('all')