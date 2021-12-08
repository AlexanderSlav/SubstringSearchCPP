import matplotlib.pyplot as plt
import pandas as pd


def draw_statistic(statistic, filename):
    plt.figure(figsize=(15, 8))
    colors = ['k', 'r']
    for object, color in zip(statistic.Algorithm.unique(), colors):
        algorithm = statistic[statistic['Algorithm'] == object]
        plt.plot(algorithm['Input_Data_Length'], algorithm['Work_Time'], color=color, label=object, linewidth=3)
        plt.scatter(algorithm['Input_Data_Length'], algorithm['Work_Time'], color=color)
        plt.grid(True)
        plt.legend(fontsize=18)
        plt.tick_params(labelsize=16)
        plt.xlabel('Input String Size', fontsize=18)
        plt.ylabel('Work Time (msc).', fontsize=18)
        plt.title('Work Time', fontsize=20)
    plt.savefig(filename)


if __name__ == "__main__":
    path_to_statistic_file = "/home/alexander/CLionProjects/SubstringSearch/statistic_with_matches.csv"
    path_to_output_image = "/home/alexander/CLionProjects/SubstringSearch/report_with_substring_matches.png"
    statistics = pd.read_csv(path_to_statistic_file, sep=";")
    draw_statistic(statistics, path_to_output_image)
