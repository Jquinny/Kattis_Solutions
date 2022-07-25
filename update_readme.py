""" Script for updating the readme with any new problems that I solved.

TODO: More in depth description
"""

import json
from pathlib import Path
from urllib.parse import quote

ROOT = Path(__file__).parent


def parse_json(path):
    """ TODO """

    # reading the info from the problem info json file
    with open(path.joinpath("problem_info.json"), 'r') as f:
        info = json.load(f)

    return info


def create_row(info, path):
    """ TODO """

    # getting the url to the kattis problem and getting it ready for readme
    kattis_url = quote(info["url"])
    title_url = f"[{info['title']}]({kattis_url})"

    # getting the github path to the language directories for this problem
    github_prob_path = ROOT.joinpath("/tree/main") / path.parent.name / path.name
    lang_paths = [github_prob_path.joinpath(lang_path) for lang_path in path.iterdir() if lang_path.is_dir()]  # might not even need a languages key in json with this method

    # adding the source file to each of the language directories
    for lang_path in lang_paths:
        source_file = [src_path.name for src_path in lang_path.iterdir()][0]  # should only be one file in the language directories
        lang_path = lang_path.joinpath(source_file)
        print(lang_path)

    # urlifying the language paths and putting them into a string
    lang_urls = ','.join([f"[{url.parent.name}]({quote(str(url))})" for url in sorted(lang_paths)])
    row = f"| {title_url} | {lang_urls} |\n"

    return row


def add_readme_rows(f):
    """ TODO """

    # go through each problem and add its row to the readme
    problems = ROOT / "problems"
    for problem in sorted(problems.iterdir()): # sorting just to be 100% sure
        info = parse_json(problem)
        row = create_row(info, problem)
        f.write(row)


def create_readme():
    """ Creates readme.md file for main repo directory. """

    header = "".join(["# Kattis Solutions\n",
            "Solutions to the [Kattis archives](https://open.kattis.com/).\n",
            "They may not be the most elegant, but they've gotten the green checkmark on kattis and that's what were here for anyways, right?\n",
            "## Problems\n", "| Problem | Languages |\n", "| - | - |\n"])

    # open the readme file for writing and add all rows
    with open(ROOT.joinpath("README.md"), 'w', encoding="utf-8") as f:
        f.write(header)
        add_readme_rows(f)


def main():
    """ TODO """

    print("Updating README ...")
    create_readme()


if __name__ == "__main__":
    main()
