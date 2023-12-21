TEMPLATE = subdirs
SUBDIRS = service app

OTHER_FILES += \
    .gitignore \
    README.md \
    rpm/fossilink.changes.in \
    rpm/fossilink.changes.run.in \
    rpm/fossilink.spec
