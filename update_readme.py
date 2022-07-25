""" Script for updating the readme with any new problems that I solved.

TODO: More in depth description
"""

import json
from pathlib import Path
import sys
from urllib.parse import quote # not sure why this wasn't working (%3A was messing stuff up in repo url)

ROOT = Path(__file__).parent


def parse_json(path):
    """ TODO """

    # reading the info from the problem info json file
    with open(path.joinpath("problem_info.json"), 'r') as f:
        info = json.load(f)

    return info


def create_row(info, path, repo): # need to fix this shit up
    """ TODO """

    # creating the title portion of the readme row
    title_url = f"[{info['title']}]({info['url']})"

    # getting the github path to the language directories for this problem
    git_paths = {}
    languages = [lang_dir for lang_dir in path.iterdir() if lang_dir.is_dir()]
    for lang_path in languages:
        git_paths[lang_path.name] = repo + lang_path.parent.name + '/' + lang_path.name # might not even need a languages key in json with this method
        source_file = [src_path.name for src_path in lang_path.iterdir()][0] # should only ever have one source file in these directories
        git_paths[lang_path.name] += '/' + source_file

    # creating the rest of the readme row
    lang_urls = ','.join([f"[{lang}]({url})" for lang, url in sorted(git_paths.items())]) # need to figure out why quote(url) was not working
    row = f"| {title_url} | {lang_urls} |\n"

    return row


def add_readme_rows(f, repo):
    """ TODO """

    # go through each problem and add its row to the readme
    problems = ROOT / "problems"
    for problem in sorted(problems.iterdir()): # sorting just to be 100% sure
        info = parse_json(problem)
        row = create_row(info, problem, repo)
        f.write(row)


def create_readme(repo):
    """ Creates readme.md file for main repo directory. """

    header = "".join(["# Kattis Solutions\n",
            "Solutions to the [Kattis archives](https://open.kattis.com/).\n",
            "They may not be the most elegant, but they've gotten the green checkmark on kattis and that's what were here for anyways, right?\n",
            "## Problems\n", "| Problem | Solutions |\n", "| - | - |\n"])

    # open the readme file for writing and add all rows
    with open(ROOT.joinpath("README.md"), 'w', encoding="utf-8") as f:
        f.write(header)
        add_readme_rows(f, repo)


def main(args):
    """ TODO """

    repo = args[1] if len(args) == 2 else "https://github.com/Jquinny/Kattis_Solutions" # url for the repo on github (necessary for readme)
    create_readme(repo.rstrip('/') + "/tree/main/problems/")
    print("README is updated.")


if __name__ == "__main__":
    main(sys.argv[1:])
