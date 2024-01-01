TEMPLATE = subdirs
SUBDIRS = service app

CONFIG += warn_on

OTHER_FILES += \
    .gitignore \
    README.md \
    rpm/fossilink.changes.in \
    rpm/fossilink.changes.run.in \
    rpm/fossilink.spec
